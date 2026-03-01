package com.example.seminar_threads_code

import kotlin.concurrent.thread

fun main() {
    val t = thread {
        Thread.sleep(2000)
        println("Child thread completed.")
    }

    println("Main thread is waiting for child thread to finish...")
    t.join() // Wait for the child thread to finish
    println("Main thread resumes after child thread completion.")
}