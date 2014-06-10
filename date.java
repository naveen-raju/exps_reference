import java.lang.System;
import java.text.SimpleDateFormat;
import java.util.Date;

public class date_test {
    public static void main() {
        SimpleDateFormat dateFormatter = new SimpleDateFormat("dow mon dd hh:mm:ss zzz yyyy");
        Date tempDate;
        tempDate = dateFormatter.parse("Wed Jun 26 15:38:12 IST 2013");
        System.out.println("Date is " + tempDate);
    }
}
