object Main {
  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val n, x = sc.nextInt()
    val list = Seq.fill(n)(sc.nextInt())
    val l = list.filter(_ != x)
    print(l.mkString(" "))
  }
}