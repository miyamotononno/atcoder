object Main {
  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val a, b = sc.nextInt()
    if (a%2==0 | b%2==0) {
      println("Even");
    } else {
      println("Odd");
    }
  }
}