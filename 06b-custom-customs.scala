object Main {
    def main(args: Array[String]): Unit = {
        val lines = scala.io.Source.fromFile("test.txt").getLines
        var arr = new Array[Int](26)
        for (a <- 0 to 25) arr(a) = 1
        var ans = 0
        for (str <- lines){
            if (str.length() == 0){
                for (a <- 0 to 25){
                    if (arr(a) == 1) ans += 1
                    arr(a) = 1
                }
            }
            else{
                for (a <- 'a' to 'z'){
                    if (str.indexOf(a) == -1) arr(a.toInt - 'a'.toInt) = 0
                }
            }
        }
        for (a <- 0 to 25){
            if (arr(a) == 1) ans += 1
        }
        println(ans)
    }
}
