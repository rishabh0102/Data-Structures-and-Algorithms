import java.util.ArrayList;
import java.util.Scanner;


public class Multiply {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		System.out.println(new Multiply().multiply(s1,s2));

	}
	public String multiply(String num1, String num2){
		int n1 = num1.length();
		int n2 = num2.length();
		
		if(n1 == 0 || n2 == 0){
			
			return "0";
		}
		int [] result = new int[n1+n2]; //A default value of 0 for arrays of integral types.
		int i_n1=0;
		int i_n2 =0;
		
		for(int i = n2-1;i>=0;i--){
			
			int d2 = Integer.parseInt(num2.charAt(i)+"");
			i_n1 = 0;
			int carry=0;
			for(int j = n1-1;j>=0;j--){
				int d1 = Integer.parseInt(num1.charAt(j)+"");
				int sum = d1*d2 + carry + result[i_n1+i_n2];
				carry = sum/10;
				result[i_n1+i_n2] = sum%10;
				i_n1++;
				
				
				

			}
			if(carry>0){
				result[i_n1+i_n2]+=carry; //Add carry to next index
			}
			i_n2++;
			
		}
		int i = result.length -1;
		while(i>=0 && result[i] == 0 ){
			i--;
		}
		if(i == -1){
			return "0";
		}
		String multiply = "";
		while(i>=0){
			multiply+=result[i--];
		}
		return multiply;
		
	}

}
