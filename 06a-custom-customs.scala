import scala.collection.mutable.Set

object Main {
    def main(args: Array[String]): Unit = {
        val lines = scala.io.Source.fromFile("test.txt").getLines
        val set : Set[Char] = Set()
        var ans = 0
        for (str <- lines){
            if (str.length() == 0){
                ans = ans + set.size
                set.clear()
            }
            for (c <- str){
                set += c
            }
        }
        ans = ans + set.size
        println(ans)
    }
}
