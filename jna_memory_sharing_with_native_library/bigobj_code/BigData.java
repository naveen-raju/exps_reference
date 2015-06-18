import java.util.List;
import java.util.Arrays;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

public class BigData extends Structure {
    public int len;
    public Pointer data;

    protected List getFieldOrder() {
        return Arrays.asList("len", "data");
    }
}
