#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <queue>
#include <random>
#include <stack>
#include <string>
#include <time.h>
#include <unordered_set>
#include <vector>

struct Pin {
  int x;
  int y;
  Pin(){};
  Pin(int _x, int _y) : x(_x), y(_y) {}
};

struct Point {
  int x;
  int y;
  Point(){};
  Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Net {
  int name;
  int hpwl, overflow{0};
  int numbOfNodesInBox;
  std::vector<Pin> pins;
  std::vector<Point> paths;

  inline bool operator()(Net const *A, Net const *B) const {
    if (A->overflow == B->overflow)
      return A->hpwl > B->hpwl;
    else
      return A->overflow < B->overflow;
  }

  int wirelength() const {
    if (paths.empty() == true)
      return 0;

    int _wirelength = 0;
    for (size_t i = 0, n = paths.size() - 1; i < n; ++i) {
      auto const &point1 = paths[i],
                 &point2 = paths[i + 1];
      _wirelength += std::abs(point1.x - point2.x) + std::abs(point1.y - point2.y);
    }
    return _wirelength;
  }
};

struct RoutingNode {
  int prevDirection;
  double cost;

  RoutingNode() : prevDirection(-1), cost(-1) {}
  inline void reset() {
    prevDirection = cost = -1;
  }
};

struct Edge {
  int capacity;
  double historicalCost;
  std::unordered_set<Net *> passNets;

  Edge() {}
  Edge(int const &capacity) : capacity(capacity), historicalCost(1) {}
  inline bool operator()(Edge const *A, Edge const *B) const {
    return A->overflow() < B->overflow();
  }

  inline int demand() const {
    return passNets.size();
  }
  inline int overflow() const {
    return std::max(demand() - capacity, 0);
  }
};

struct Node {
  int x, y;
  double cost;

  Node() {}
  Node(int x, int y, double cost) : x(x), y(y), cost(cost) {}
  inline bool operator()(Node const &A, Node const &B) const {
    return A.cost > B.cost;
  }
};

enum Direction {
  STOP = -1,
  LEFT,
  RIGHT,
  UP,
  DOWN
};

struct Router {
  int Grid_H_numb, Grid_V_numb;
  int H_capacity, V_capacity;
  int NumbNets{0};
  std::vector<Net> nets;

  double baseCost = 0;
  std::vector<std::vector<Edge>> hEdges, vEdges;
  std::vector<std::vector<RoutingNode>> routingMap;
};

// --------------------- Paring Files ---------------------
Router *parseNets(char *fpath) {
  FILE *netFile;
  if (!(netFile = fopen(fpath, "r"))) {
    std::cerr << " Can not open .modified.txt file\n";
    exit(1);
  }
  Router *rgraph = new Router();
  fscanf(netFile, "grid %d %d\n", &(rgraph->Grid_H_numb), &(rgraph->Grid_V_numb));
  fscanf(netFile, "vertical capacity %d\n", &(rgraph->V_capacity));
  fscanf(netFile, "horizontal capacity %d\n", &(rgraph->H_capacity));
  fscanf(netFile, "num net %d\n", &(rgraph->NumbNets));

  std::cout << "grid H: " << rgraph->Grid_H_numb << " grid V: " << rgraph->Grid_V_numb << std::endl;
  std::cout << "V capacity: " << rgraph->V_capacity << std::endl;
  std::cout << "H capacity: " << rgraph->H_capacity << std::endl;
  std::cout << "NumbNets: " << rgraph->NumbNets << std::endl;

  rgraph->hEdges = std::vector<std::vector<Edge>>(rgraph->Grid_V_numb, std::vector<Edge>(rgraph->Grid_H_numb - 1, rgraph->H_capacity));
  rgraph->vEdges = std::vector<std::vector<Edge>>(rgraph->Grid_V_numb - 1, std::vector<Edge>(rgraph->Grid_H_numb, rgraph->V_capacity));
  rgraph->routingMap = std::vector<std::vector<RoutingNode>>(rgraph->Grid_V_numb, std::vector<RoutingNode>(rgraph->Grid_H_numb));

  rgraph->nets.resize(rgraph->NumbNets);
  std::vector<std::vector<int>> map(rgraph->Grid_V_numb, std::vector<int>(rgraph->Grid_H_numb, 0));
  for (int i = 0; i < rgraph->NumbNets; i++) {
    Pin tmp1, tmp2;
    fscanf(netFile, "net%d %d 2\n", &rgraph->nets[i].name, &rgraph->nets[i].name);
    fscanf(netFile, "%d %d\n", &tmp1.x, &tmp1.y);
    fscanf(netFile, "%d %d\n", &tmp2.x, &tmp2.y);
    rgraph->nets[i].pins.emplace_back(tmp1);
    rgraph->nets[i].pins.emplace_back(tmp2);
    rgraph->nets[i].hpwl = std::abs(tmp1.x - tmp2.x) + std::abs(tmp1.y - tmp2.y);
    map[tmp1.y][tmp1.x] = 1;
    map[tmp2.y][tmp2.x] = 1;
  }

  for (int i = 0; i < rgraph->NumbNets; i++) {
    int minX = std::min(rgraph->nets[i].pins[0].x, rgraph->nets[i].pins[1].x);
    int minY = std::min(rgraph->nets[i].pins[0].y, rgraph->nets[i].pins[1].y);
    int maxX = std::max(rgraph->nets[i].pins[0].x, rgraph->nets[i].pins[1].x);
    int maxY = std::max(rgraph->nets[i].pins[0].y, rgraph->nets[i].pins[1].y);
    int block_num = 0;
    for (int row = minY; row <= maxY; row++) {
      for (int col = minX; col <= maxX; col++) {
        if (!(col == minX && row == minY)) {
          if (!(col == maxX && row == maxY)) {
            if (map[row][col] == 1)
              block_num++;
          }
        }
      }
    }
    rgraph->nets[i].numbOfNodesInBox = block_num;
  }

  fclose(netFile);
  return rgraph;
}

void writeSolution(char *fpath, Router *rgraph) {
  FILE *outFile;
  if (!(outFile = fopen(fpath, "w"))) {
    std::cerr << " Can not open .result file\n";
    exit(1);
  }
  std::sort(rgraph->nets.begin(), rgraph->nets.end(), [](const Net &A, const Net &B) { return A.name < B.name; });
  for (int i = 0; i < rgraph->NumbNets; i++) {
    fprintf(outFile, "net%d %d\n", rgraph->nets[i].name, rgraph->nets[i].name);
    for (int j = 0, m = rgraph->nets[i].paths.size() - 1; j < m; j++) {
      fprintf(outFile, "(%d, %d, 1)-(%d, %d, 1)\n", rgraph->nets[i].paths[j].x, rgraph->nets[i].paths[j].y, rgraph->nets[i].paths[j + 1].x, rgraph->nets[i].paths[j + 1].y);
    }
    fprintf(outFile, "!\n");
  }
  fclose(outFile);
}

Edge *getEdge(int const &x, int const &y, int const &direction, Router *rgraph) {
  assert(direction != Direction::STOP);

  if (direction == Direction::LEFT)
    return &rgraph->hEdges.at(y).at(x - 1);
  else if (direction == Direction::RIGHT)
    return &rgraph->hEdges.at(y).at(x);
  else if (direction == Direction::UP)
    return &rgraph->vEdges.at(y).at(x);
  else if (direction == Direction::DOWN)
    return &rgraph->vEdges.at(y - 1).at(x);
  return nullptr;
}

double calCost(Edge const *edge, Router *rgraph) {
  double historical = 0;
  if (edge->demand() > edge->capacity)
    historical = edge->historicalCost + 1;
  else
    historical = edge->historicalCost;
  double penalty = std::pow(static_cast<double>(edge->demand() + 1) / edge->capacity, 5.0);
  return rgraph->baseCost + historical * penalty;
}

Node outOfBoundary(-1, -1, -1);
Node wavePropagation(Node const &current, Node const &target, int const &direction, Router *rgraph) {
  auto next = current;
  if (direction == Direction::LEFT) {
    next.x -= 1;
    if (next.x < 0)
      return outOfBoundary;
    if (current.x <= target.x)
      next.cost += 1;
  } else if (direction == Direction::RIGHT) {
    next.x += 1;
    if (next.x > rgraph->Grid_H_numb - 1)
      return outOfBoundary;
    if (current.x >= target.x)
      next.cost += 1;
  } else if (direction == Direction::UP) {
    next.y += 1;
    if (next.y > rgraph->Grid_V_numb - 1)
      return outOfBoundary;
    if (current.y >= target.y)
      next.cost += 1;
  } else if (direction == Direction::DOWN) {
    next.y -= 1;
    if (next.y < 0)
      return outOfBoundary;
    if (current.y <= target.y)
      next.cost += 1;
  } else {
    return outOfBoundary;
  }
  next.cost += calCost(getEdge(current.x, current.y, direction, rgraph), rgraph);
  return next;
}

void traceBack(Net *net, Router *rgraph) {
  net->paths.clear();
  int x = net->pins[1].x, y = net->pins[1].y;
  while (rgraph->routingMap.at(y).at(x).prevDirection != -1) {
    net->paths.emplace_back(x, y);
    int const &direction = rgraph->routingMap.at(y).at(x).prevDirection;
    if (direction == Direction::LEFT) {
      getEdge(x, y, Direction::RIGHT, rgraph)->passNets.insert(net);
      x += 1;
    } else if (direction == Direction::RIGHT) {
      getEdge(x, y, Direction::LEFT, rgraph)->passNets.insert(net);
      x -= 1;
    } else if (direction == Direction::UP) {
      getEdge(x, y, Direction::DOWN, rgraph)->passNets.insert(net);
      y -= 1;
    } else if (direction == Direction::DOWN) {
      getEdge(x, y, Direction::UP, rgraph)->passNets.insert(net);
      y += 1;
    }
  }
  net->paths.emplace_back(x, y);
}

void routeNet(Net *net, Router *rgraph) {
  Node source(net->pins[0].x, net->pins[0].y, 0), target(net->pins[1].x, net->pins[1].y, -1);

  for (auto &y : rgraph->routingMap)
    for (auto &x : y)
      x.reset();
  rgraph->routingMap.at(source.y).at(source.x).cost = 0;

  std::vector<int> directions(2, Direction::STOP); // {direction x, direction y}
  if (source.x > target.x)
    directions.at(0) = Direction::LEFT;
  else if (source.x < target.x)
    directions.at(0) = Direction::RIGHT;
  if (source.y < target.y)
    directions.at(1) = Direction::UP;
  else if (source.y > target.y)
    directions.at(1) = Direction::DOWN;

  std::priority_queue<Node, std::vector<Node>, Node> routingQueue;
  routingQueue.push(source);
  while (routingQueue.empty() == false) {
    auto current = routingQueue.top();
    routingQueue.pop();

    if (current.x == target.x && current.y == target.y) {
      target.cost = current.cost;
      continue;
    }

    if (target.cost != -1 && current.cost >= target.cost)
      continue;

    for (auto const direction : directions) {
      auto const &next = wavePropagation(current, target, direction, rgraph);
      if (next.cost == -1)
        continue;

      auto &routingNode = rgraph->routingMap.at(next.y).at(next.x);
      if (routingNode.cost != -1 && next.cost >= routingNode.cost)
        continue;

      routingNode.cost = next.cost;
      routingNode.prevDirection = direction;
      routingQueue.push(next);
    }
  }

  traceBack(net, rgraph);
}

void getRipUpQueue(std::priority_queue<Edge *, std::vector<Edge *>, Edge> &ripUpQueue, Router *rgraph) {
  for (auto &y : rgraph->hEdges)
    for (auto &x : y)
      if (x.overflow() > 0) {
        x.historicalCost += 1;
        ripUpQueue.push(&x);
      }
  for (auto &y : rgraph->vEdges)
    for (auto &x : y)
      if (x.overflow() > 0) {
        x.historicalCost += 1;
        ripUpQueue.push(&x);
      }
}

void rerouteNet(Net *net, Router *rgraph) {
  Node source(net->pins[0].x, net->pins[0].y, 0), target(net->pins[1].x, net->pins[1].y, -1);

  for (auto &y : rgraph->routingMap)
    for (auto &x : y)
      x.reset();
  rgraph->routingMap.at(source.y).at(source.x).cost = 0;

  std::priority_queue<Node, std::vector<Node>, Node> routingQueue;
  routingQueue.push(source);
  while (routingQueue.empty() == false) {
    auto current = routingQueue.top();
    routingQueue.pop();

    if (current.x == target.x && current.y == target.y) {
      target.cost = current.cost;
      continue;
    }

    if (target.cost != -1 && current.cost >= target.cost)
      continue;

    for (int direction = 0; direction < 4; ++direction) {
      auto const &next = wavePropagation(current, target, direction, rgraph);
      if (next.cost == -1)
        continue;

      auto &routingNode = rgraph->routingMap.at(next.y).at(next.x);
      if (routingNode.cost != -1 && next.cost >= routingNode.cost)
        continue;

      routingNode.cost = next.cost;
      routingNode.prevDirection = direction;
      routingQueue.push(next);
    }
  }

  traceBack(net, rgraph);
}

void ripUpReroute(std::unordered_set<Net *> passNets, Router *rgraph) {
  std::priority_queue<Net *, std::vector<Net *>, Net> rerouteQueue;
  for (auto net : passNets) {
    int cost = 0;
    for (size_t i = 0; i < net->paths.size() - 1; ++i) {
      auto const &point1 = net->paths.at(i),
                 &point2 = net->paths.at(i + 1);
      int direction = Direction::STOP;
      if (point1.x > point2.x && point1.y == point2.y)
        direction = Direction::LEFT;
      else if (point1.x < point2.x && point1.y == point2.y)
        direction = Direction::RIGHT;
      else if (point1.x == point2.x && point1.y < point2.y)
        direction = Direction::UP;
      else if (point1.x == point2.x && point1.y > point2.y)
        direction = Direction::DOWN;
      else
        continue;

      auto edge = getEdge(point1.x, point1.y, direction, rgraph);
      cost += edge->overflow();
      edge->passNets.erase(net);
    }
    net->overflow = cost;
    net->paths.clear();
    rerouteQueue.push(net);
  }

  while (rerouteQueue.empty() == false) {
    auto net = rerouteQueue.top();
    rerouteQueue.pop();
    rerouteNet(net, rgraph);
  }
}

int calTotalOverflow(Router *rgraph) {
  int overflow = 0;
  for (auto const &y : rgraph->hEdges)
    for (auto const &x : y)
      overflow += x.overflow();
  for (auto const &y : rgraph->vEdges)
    for (auto const &x : y)
      overflow += x.overflow();
  return overflow;
}

int calWirelength(Router *rgraph) {
  int wirelength = 0;
  for (auto const &net : rgraph->nets)
    wirelength += net.wirelength();
  return wirelength;
}

// --------------------- Global routing ---------------------
void Global_Routing(Router *rgraph) {
  std::shuffle(rgraph->nets.begin(), rgraph->nets.end(), std::default_random_engine(time(nullptr)));
  for (auto &net : rgraph->nets)
    routeNet(&net, rgraph);
  int overflow = calTotalOverflow(rgraph);
  std::cerr << "initial overflow:   " << overflow << std::endl;

  int iteration = 0;
  while (overflow > 0 and iteration++ < 100) {
    rgraph->baseCost = 1.0 - exp(-5 * exp(-0.1 * iteration));
    std::priority_queue<Edge *, std::vector<Edge *>, Edge> ripUpQueue;
    getRipUpQueue(ripUpQueue, rgraph);
    int tk = 0;
    while (overflow > 0 && ripUpQueue.empty() == false && tk++ < 100) {
      auto edge = ripUpQueue.top();
      ripUpQueue.pop();
      ripUpReroute(edge->passNets, rgraph);
      overflow = calTotalOverflow(rgraph);
    }
    std::cerr << "reroute overflow:   " << overflow << std::endl;
  }
  std::cerr << "total wirelength:   " << calWirelength(rgraph) << std::endl;
}

// --------------------- Main ---------------------
int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: ./route <input_file> <output_file>" << std::endl;
    return -1;
  }

  Router *rgraph = parseNets(argv[1]);

  double cpu0 = (double)clock() / CLOCKS_PER_SEC;
  std::cout << "start global_routing" << std::endl;
  Global_Routing(rgraph);
  double cpu1 = (double)clock() / CLOCKS_PER_SEC;
  std::cout << "\nTime(s): " << cpu1 - cpu0 << std::endl;

  writeSolution(argv[2], rgraph);
  delete rgraph;

  return 0;
}