import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import java.util.List;
import java.util.Arrays;

public class MyData extends Structure {
    public byte[] name = new byte[15];
    public byte[] lastname = new byte[15];
    public int age;

    protected List getFieldOrder() {
        return Arrays.asList("name", "lastname", "age");
    }
    public MyData(Pointer p) {
        super(p);
	//allocateMemory();
	read();
    }

}

