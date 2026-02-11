import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Hello {
    public static void main(String[] args) {
        System.out.println("Hello from Java");
        DateTimeFormatter fmt = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        System.out.println(LocalDateTime.now().format(fmt));
    }
}
