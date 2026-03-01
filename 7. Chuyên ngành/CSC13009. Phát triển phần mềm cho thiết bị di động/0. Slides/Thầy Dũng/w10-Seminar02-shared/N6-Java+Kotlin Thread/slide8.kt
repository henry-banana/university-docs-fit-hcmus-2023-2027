package com.example.seminar_threads_code

import kotlin.concurrent.thread

fun main() {
    var counter = 0
    val lock = Object()
    val threads = mutableListOf<Thread>()

    for (i in 1..10000) {
        val t = thread {
            synchronized(lock) {
                counter++ // Safe: Only one thread can increment at a time
            }
        }
        threads += t
    }

    threads.forEach { it.join() } // Wait for all threads to finish
    println("Final value of counter: $counter")
}