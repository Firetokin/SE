import java.util.Scanner;
public class NumeralCalculations{
	public static void main(String[] args){
		int n = 0, maxSum = 0, temp = 0, i ,j ;
		Scanner ar = new Scanner(System.in);
		System.out.println("���������������Сn= ");
		n = ar.nextInt();
		int[] array = new int[n];
		for(i = 0; i < n; i++){
			array[i] = ar.nextInt();
		}
		for(i = 0; i < array.length ; i++){
			temp = 0;
			for(j = i; j < array.length; j++){
				temp += array[j];
				if(maxSum < temp){
					maxSum = temp;
				}	
			}
		}
		System.out.println("����������������֮�͵����ֵΪ:" + maxSum);
	}
}