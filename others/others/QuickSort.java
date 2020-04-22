
public class QuickSort {
	private static int count;
	/**
	 * ����
	 * @param args
	 */
	public static void main(String[] args) {
		int[] num = {3,45,78,64,52,11,64,55,99,11,18};
		System.out.println(arrayToString(num,"δ����"));
		QuickSort(num,0,num.length-1);
		System.out.println(arrayToString(num,"����"));
		System.out.println("���������"+num.length);
		System.out.println("ѭ��������"+count);
		
	}
	/**
	 * ��������
	 * @param num	���������
	 * @param left	�����ǰ��
	 * @param right �������
	 */
	private static void QuickSort(int[] num, int left, int right) {
		//���left����right��������ֻ��һ��Ԫ�أ�ֱ�ӷ���
		if(left>=right) {
			return;
		}
		//��������ߵ�Ԫ��Ϊ��׼ֵ
		int key=num[left];
		//�����б�keyС�ķ�����ߣ���key��ķ����ұߣ�keyֵ�±�Ϊi
		int i=left;
		int j=right;
		while(i<j){
			//j�����ƣ�ֱ��������keyС��ֵ
			while(num[j]>=key && i<j){
				j--;
			}
			//i�����ƣ�ֱ��������key���ֵ
			while(num[i]<=key && i<j){
				i++;
			}
			//i��jָ���Ԫ�ؽ���
			if(i<j){
				int temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}
		num[left]=num[i];
		num[i]=key;
		count++;
		QuickSort(num,left,i-1);
		QuickSort(num,i+1,right);
	}
	/**
	 * ��һ��int��������ת��Ϊ�ַ���
	 * @param arr
	 * @param flag
	 * @return
	 */
	private static String arrayToString(int[] arr,String flag) {
		String str = "����Ϊ("+flag+")��";
		for(int a : arr) {
			str += a + "\t";
		}
		return str;
	}
}