package com.example.seminar_threads_code

import kotlin.concurrent.thread

fun main() {
    // Create and start a thread using Kotlin's thread function
    thread(start = true, name = "MyKotlinThread") {
        println("Running on Thread: ${Thread.currentThread().name}")
        Thread.sleep(1000)
        println("Work completed!")
    }
}