import java.io.File;

fun main(args: Array<String>){
    var idx = intArrayOf(0,0,0,0,0);
    var ans = intArrayOf(0,0,0,0,0);
    var step = intArrayOf(1,3,5,7,1);
    var bool = 1;
    File("test.txt").forEachLine{
        for (i in 0..3){
            if (it[idx[i]] == '#') ans[i]++;
            idx[i] += step[i];
            idx[i] %= it.length;
        }
        if (bool == 1){
            if (it[idx[4]]=='#') ans[4]++;
            idx[4] += step[4];
            idx[4] %= it.length;
        }
        bool = bool.xor(1);
    }
    println(ans[0]*ans[1]*ans[2]*ans[3]*ans[4]);
}