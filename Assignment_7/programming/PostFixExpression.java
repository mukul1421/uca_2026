import java.util.*;


public class PostFixExpression {

	public static int PostFix(String str) {

		Stack <Integer> s = new Stack <>();

		for(char c : str.toCharArray()) {
		
			if(c == '+' ||
			   c == '-' ||
			   c == '/' ||
			   c == '*' ) {
			   
			   int a = s.pop();
			   int b = s.pop();

			   switch(c) {
			   
				   case '+':
					s.push(a + b);
					break;
			
				   case '-':
					s.push(b - a);
					break;
					
				   case '/':
					s.push(b / a);
					break;

				   case'*':
					s.push(a * b);		   
					break;	
					   
					   
			   }

			}
			else {

			    s.push(c-'0');
			
			}	


		
		}


		return s.pop();
	}

		public static void main (String args[]) {
		

			String str = "231*+9-";

			System.out.println("The Answer for postfix expression is :"+PostFix(str));
		
		
		
		}

}
