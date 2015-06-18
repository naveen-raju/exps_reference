import java.text.SimpleDateFormat;
import java.util.Date;

	public class timetest {
		public static void main(String[] args)
        {
//            SystemCurrentTimeSource.class
			long time_val = System.currentTimeMillis();
			Date date = new Date(time_val);
			SimpleDateFormat fmt = new SimpleDateFormat("MMM d, yyyy HH:mm:ss");  
			String timestr = fmt.format(date);
			System.out.println("Current time in jvm " + timestr);
		}
	}
