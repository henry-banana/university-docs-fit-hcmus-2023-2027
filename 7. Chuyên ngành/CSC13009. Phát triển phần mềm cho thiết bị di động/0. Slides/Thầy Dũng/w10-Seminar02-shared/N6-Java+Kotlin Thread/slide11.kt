package com.example.seminar_threads_code

import java.util.LinkedList
import kotlin.concurrent.thread

fun main() {
    val buffer = LinkedList<Int>()
    val capacity = 5
    val lock = Object()

    // Producer Thread
    thread {
        while (true) {
            synchronized(lock) {
                while (buffer.size == capacity) lock.wait() // Wait if full
                val item = (1..100).random()
                buffer.add(item)
                println("Added item $item. Current buffer size: ${buffer.size}")
                lock.notifyAll() // Notify consumer threads
            }
            Thread.sleep(500) // Simulate time taken to produce an item
        }
    }

    // Consumer Thread
    thread {
        while (true) {
            synchronized(lock) {
                while (buffer.isEmpty()) lock.wait() // Wait if empty
                val item = buffer.removeFirst()
                println("Removed item $item. Current buffer size: ${buffer.size}")
                lock.notifyAll() // Notify producer threads
            }
            Thread.sleep(1000) // Simulate time taken to consume an item
        }
    }
}