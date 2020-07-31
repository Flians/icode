#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
class LRU
{
private:
    /* data */
    vector<T> data;
    unordered_map<T, int> index;
    int length;
public:
    LRU(/* args */);
    LRU(int length);
    ~LRU();
    bool get(T in);
    void push(T in);
};

template <typename T>
LRU<T>::LRU(/* args */)
{
    this->length = 10;
    this->data.reserve(this->length);
}

template <typename T>
LRU<T>::LRU(int length)
{
    this->length = length;
    this->data.reserve(this->length);
}

template <typename T>
LRU<T>::~LRU()
{
    vector<T>().swap(this->data);
    index.clear();
}

template <typename T>
bool LRU<T>::get(T in) {
    if (this->index.count(in)) {
        int index_ = this->index[in];
        this->data.emplace_back(this->data[index_]);
        this->data.erase(this->data.size() + index_);
        this->index[in] = this->data.size() - 1;
        return true;
    }
    return false;
}
    
template <typename T>
void LRU<T>::push(T in) {
    // exist
    if (this->index.count(in)) {
        this->data.erase(this->data.size() + this->index[in]);
    } else {
        if (this->data.size() == this->length) {
            this->data.erase(this->data.begin());
        }
    }
    this->index[in] = this->data.size();
    this->data.emplace_back(in);
}

int main() {

    return 0;
}