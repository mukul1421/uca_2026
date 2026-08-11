import java.util.*;

public class base64Encoding {
	
	private static final String base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	public static String encodeBase64(String str) {
	
		StringBuilder chunk = new StringBuilder();
		StringBuilder encoded = new StringBuilder();
		
		for(int i=0; i<str.length(); i++) {

			chunk.append(str.charAt(i));

			if(chunk.length() == 3) {
				encoded.append( convertChunk(chunk.toString()) );
				chunk.setLength(0);
			}

		}
		
		if(chunk.length() != 0) {
			encoded.append(convertChunk(chunk.toString()));
		}

		return encoded.toString();

	}

	public static String convertChunk(String chunk) {
		
		StringBuilder convertedChunk = new StringBuilder();
		int bitForm = 0;

		for(int i=0; i<chunk.length(); i++) {
		
			int value = (int) chunk.charAt(i);
			bitForm = bitForm | ( value << (16-(i*8)));

		
		}

		int groups = chunk.length() + 1;

		for(int i=0; i<groups; i++) {
			
			int shift = 18 - (i*6);
			convertedChunk.append(base64Chars.charAt( (bitForm >> shift) & 63 ));
		
		}

		while(convertedChunk.length() < 4) {
		
			convertedChunk.append("=");

		}

		return convertedChunk.toString();

	}

	public static void main(String[] args) {
	
		Scanner sc = new Scanner(System.in);

		base64Encoding be = new base64Encoding();
		
		System.out.println("Enter your string: ");
		String str = sc.nextLine();

		String result = encodeBase64(str);

		System.out.println(result);

		sc.close();
	
	}
}
