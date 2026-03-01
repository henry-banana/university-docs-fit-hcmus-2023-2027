package com.example.seminar_threads_code

fun main() {
    // Create a Runnable using a lambda expression
    val myRunnable = Runnable {
        println("Running on Thread: ${Thread.currentThread().name}")
        Thread.sleep(1000) // Simulate some work with sleep
        println("Work completed!")
    }

    val thread = Thread(myRunnable)
    thread.start() // Start the thread
}