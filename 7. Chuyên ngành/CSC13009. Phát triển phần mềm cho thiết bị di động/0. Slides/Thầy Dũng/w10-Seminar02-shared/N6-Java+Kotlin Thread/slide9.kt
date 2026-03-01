package com.example.seminar_threads_code

import java.util.concurrent.atomic.AtomicInteger

fun main() {
    val atomicCounter = AtomicInteger(0)
    var regularCounter = 0

    // Create 100 threads, each incrementing both counters 1000 times
    val threads = List(100) {
        Thread {
            repeat(1000) {
                atomicCounter.incrementAndGet()
                regularCounter++ // race condition expected
            }
        }
    }

    // Start and join all threads
    threads.forEach { it.start() }
    threads.forEach { it.join() }

    // Atomic counter should be 100000 while regularCounter may be less
    println("Expected: ${100 * 1000}")
    println("Atomic: ${atomicCounter.get()}")
    println("Regular: $regularCounter")
}