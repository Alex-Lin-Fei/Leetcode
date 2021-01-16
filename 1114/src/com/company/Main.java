package com.company;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Foo foo = new Foo();
        Thread A = new Thread(() -> {
            try {
                foo.first(() -> System.out.println("first"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread B = new Thread(() -> {
            try {
                foo.second(() -> System.out.println("second"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread C = new Thread(() -> {
            try {
                foo.third(() -> System.out.println("third"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        A.start();
        B.start();
        C.start();
    }
}

class Foo {
    private boolean turnA = true;
    private boolean turnB = false;
    private boolean turnC = false;

    public Foo() {

    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized (this) {
            while (!turnA)
                this.wait();
            // printFirst.run() outputs "first". Do not change or remove this line.

            printFirst.run();
            turnB = true;
            turnA = false;
            this.notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized (this) {
            while (!turnB)
                this.wait();
            // printSecond.run() outputs "second". Do not change or remove this line.

            printSecond.run();
            turnB = false;
            turnC = true;
            this.notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized (this) {
            while (!turnC)
                this.wait();
            // printThird.run() outputs "third". Do not change or remove this line.

            printThird.run();

            turnC = false;
            turnA = true;
            this.notifyAll();
        }
    }
}

