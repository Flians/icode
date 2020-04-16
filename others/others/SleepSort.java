/**
 * sleep sort, very interesting!
 */
public class SleepSort implements Runnable{
    private String num;
    public SleepSort(String num) {
        this.num = num;
    }

    public void run(){
        try {
            Thread.sleep(Integer.parseInt(num));
            System.out.println(num);            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        for(int i = 0; i < args.length; i++){
            new Thread(new SleepSort(args[i])).start();
        }
    }
}