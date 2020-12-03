import java.io.File;

fun main(args: Array<String>){
    var idx = 0; var ans = 0;
    File("test.txt").forEachLine{
        if (it[idx] == '#') ans++;
        idx += 3; 
        idx %= it.length;
    }
    println(ans);
}