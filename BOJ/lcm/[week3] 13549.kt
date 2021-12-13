package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.min
import java.util.*

fun solution(n: Int, k: Int):String{
    var answer = Int.MAX_VALUE
    val check =  BooleanArray(200001, {i -> false})
    val q = PriorityQueue<Pair<Int,Int>>(kotlin.Comparator { o1, o2 ->  o1.second - o2.second}) // second에 대해 min heap, first = pos, second = weight
    // val q = PriorityQueue<Int>() // min Heap
    // val q = PriorityQueue<Int>(Comparator.reversedOrder()) max Heap
    q.offer(Pair(n, 0)) //add는 q 사이즈 꽉 찰 시 오류

    while(q.isNotEmpty()){
        val top = q.poll()
        if(top.first == k){
            answer = min(answer, top.second)
            continue
        }
        if(top.second > answer) break
        if(!check[top.first] && top.first in 0..100000){ // 방문 안한 경우
            check[top.first] = true
            if(top.first < k){
                if(!check[top.first+1]) q.offer(Pair(top.first+1, top.second+1))
                if(!check[top.first*2]) q.offer(Pair(top.first*2, top.second))
            }
            if(top.first >= 1 && !check[top.first-1]) q.offer(Pair(top.first-1, top.second+1))
        }
    }

    return answer.toString()
}

fun main(args: Array<String>){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (n, k) = br.readLine().split(" ").map { it.toInt() }

    bw.write(solution(n, k))
    bw.flush()
    br.close()
    bw.close()
}