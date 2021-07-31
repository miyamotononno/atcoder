object Main {
  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val v,t,s,d = sc.nextInt()
    if (v*t <= d && d <= v*s) {
      println("No")
    } else {
      println("Yes")
    }
  }
}