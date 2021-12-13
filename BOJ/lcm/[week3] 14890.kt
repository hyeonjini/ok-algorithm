package boj

import com.sun.org.apache.xpath.internal.operations.Bool
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.abs

// boj 14890 경사로

fun solution(n:Int, l:Int, arr:MutableList<Int>):Boolean{
    var answer = true
    val visited = BooleanArray(n, {i -> false})

    for(i in 0..n-2){
        if(arr[i] - arr[i+1] == 1){ // 왼쪽에서 오른쪽으로 내려가는 경우
            for(j in i+1..i+l){
                if(j>n-1 || visited[j] || arr[i+1] != arr[j]) return false // boundary or 이미 경사로 한 경우 or 높이 차이 나는 경우 -> 불가능
                visited[j] = true
            }
        } else if(arr[i] - arr[i+1] == -1){ // 왼쪽에서 오른쪽으로 올라가는 경우
            for(j in i downTo i-l+1){
                if(j < 0 || visited[j] || arr[i] != arr[j]) return false
                visited[j] = true
            }
        }
        if(abs(arr[i] - arr[i+1]) > 1) return false// 높이 차 2이상 불가능
    }

    return answer
}

fun main(args:Array<String>){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (n, l) = br.readLine().split(" ").map { it.toInt() }

    val arr:MutableList<MutableList<Int>> = mutableListOf()
    val transposedArr:MutableList<MutableList<Int>> = mutableListOf()
    for(i in 0..n-1)
        transposedArr.add(i, mutableListOf())
    for(i in 0..n-1){
        val input = br.readLine().split(" ").map { it.toInt() }.toList() as MutableList<Int>
        arr.add(input)

        for(i in 0..n-1)
            transposedArr[i].add(input[i])
    }
    var answer = 0
    for(i in 0.. n-1){
        if(solution(n, l, arr[i])) ++answer
        if(solution(n, l, transposedArr[i])) ++answer
    }
    bw.write(answer.toString())
    bw.flush()
    br.close()
    bw.close()
}