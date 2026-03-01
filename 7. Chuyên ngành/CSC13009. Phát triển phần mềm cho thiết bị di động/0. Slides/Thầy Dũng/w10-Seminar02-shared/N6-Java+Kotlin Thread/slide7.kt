package com.example.seminar_threads_code

import kotlin.concurrent.thread

fun main() {
    var counter = 0
    val threads = mutableListOf<Thread>()

    // Create 10,000 threads, each incrementing the counter by 1
    // Expected final value of counter is 10,000
    for (i in 1..10000) {
        val t = thread {
            counter++ // This is not atomic and may lead to race conditions
        }

        threads += t
    }

    threads.forEach { it.join() } // Wait for all threads to finish
    println("Final value of counter: $counter")
}