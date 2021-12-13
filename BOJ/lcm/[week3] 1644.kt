package boj

// 소수의 연속합 1644번

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter


fun solution(number: Int): String{
    val numbers = MutableList<Int>(number+1, {i -> i})
    val odds:MutableList<Int> = mutableListOf()
    var answer = 0

    for(i in 2..number){ // 에스테라토스의 체
        if(numbers[i] != 0) odds.add(i)
        for(j in i+i..number step(i)) numbers[j] = 0
    }

    var sum = 0
    var start = 0
    var end = 0

    while(true){
        if(sum >= number){
            if(sum == number) answer++
            sum -= odds[start++]
        }else if(sum < number){
            if(end == odds.size) break
            sum += odds[end++]
        }
    }

    return answer.toString()
}

fun main(args:Array<String>){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val number = br.readLine().toInt()

    bw.write(solution(number))
    bw.flush()
    bw.close()
    br.close()
}