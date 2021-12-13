package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.StringBuilder

fun solution(number: String, k: Int): String {
    var answer = ""
    val builder = StringBuilder()
    var kk = k // k는 val이라서 안됨..

    for(i in number.indices){
        while(builder.isNotEmpty() && kk>0 && builder[builder.lastIndex] < number[i]){
            builder.setLength(builder.length-1)
            kk--
        }
        if(kk == 0){
            builder.append(number.substring(i))
            break
        }

        builder.append(number[i])
    }
    answer = builder.toString().substring(0, builder.length - kk)

    return answer
}

fun main(args: Array<String>){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, k) = br.readLine().split(" ").map{ it.toInt() }
    val number = br.readLine().toString()

    bw.write(solution(number, k))
    bw.flush()
    bw.close()
    br.close()
}