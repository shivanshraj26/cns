import java.security.MessageDigest;
import java.util.Scanner;

public class sha {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the message to be hashed: ");
        String text = sc.nextLine();

        MessageDigest digest = MessageDigest.getInstance("SHA-512");
        byte[] hashBytes = digest.digest(text.getBytes("UTF-8"));
        StringBuilder hexString = new StringBuilder();
            
        for (byte hashByte : hashBytes) {
            String hex = Integer.toHexString(0xff & hashByte);
            if (hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        System.out.println("SHA-512 Hash: " + hexString.toString());  
    }
}
