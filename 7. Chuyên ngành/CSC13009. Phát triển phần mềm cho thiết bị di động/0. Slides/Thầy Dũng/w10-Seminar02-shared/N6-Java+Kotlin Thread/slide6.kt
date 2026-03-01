package com.example.seminar_threads_code

import kotlin.concurrent.thread
import kotlin.random.Random

fun main() {
    println("=== RACE STARTS ===")

    val runners = listOf("Blue-thread", "Red-thread", "Yellow-thread")

    for (name in runners) {
        thread(name = name) {
            for (step in 1..5) {
                println("- $name is at step $step")
                
                // Simulate variable speed by sleeping for a random time
                // between 10 to 100 milliseconds
                Thread.sleep(Random.nextLong(10, 100))
            }
            println("$name has finished!")
        }
    }

    println("=== RACE ENDS ===")
}