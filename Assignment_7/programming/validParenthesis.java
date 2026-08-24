import java.util.*;

public class validParenthesis {

	public static boolean isBalanced (String str) {

		Stack <Character> s = new Stack<>();
	
		for(char c : str.toCharArray()) {
			if (c == '{' || c == '[' || c == '(') {
				s.push(c);
			}

			else if (s.isEmpty()) return false;
               
			else if((c == '}' && s.peek() != '{') ||
			        (c == ']' && s.peek() != '[') ||
	  		        (c == ')' && s.peek() != '(') ) 
					return false;

			else s.pop();

		}

		return s.isEmpty();
	}


	public static void main (String [] args) {

		String str = "{}[]()";

		if(isBalanced(str)) System.out.println("VALID");

		else System.out.println("INVALIID");
		

	}
}



