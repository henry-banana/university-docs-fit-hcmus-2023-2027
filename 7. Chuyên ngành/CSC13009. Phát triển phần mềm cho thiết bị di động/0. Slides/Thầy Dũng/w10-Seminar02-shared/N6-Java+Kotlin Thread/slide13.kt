package com.example.seminar_threads_code

import java.util.concurrent.Executors

fun main() {
    // Create a Thread Pool with 2 threads
    val executor = Executors.newFixedThreadPool(2)

    // Submit 10 tasks to the pool
    for (i in 1..10) {
        executor.submit {
            println("Task $i is running on Thread: ${Thread.currentThread().name}")
            Thread.sleep(500)
        }
    }

    executor.shutdown() // Shutdown the executor after tasks are done
}