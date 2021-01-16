package com.company;

import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

public class Main {

    public static void main(String[] args) {
        // write your code here
        ZeroEvenOdd zeroEvenOdd = new ZeroEvenOdd(6);
        IntConsumer printZero = new IntConsumer() {
            @Override
            public void accept(int value) {
                System.out.print(value);
            }
        };

        IntConsumer printEven = new IntConsumer() {
            @Override
            public void accept(int value) {
                System.out.print(value);
            }
        };

        IntConsumer printOdd = new IntConsumer() {
            @Override
            public void accept(int value) {
                System.out.print(value);
            }
        };

        Thread A = new Thread(() -> {
            try {
                zeroEvenOdd.zero(printZero);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        Thread B = new Thread(() -> {
            try {
                zeroEvenOdd.even(printEven);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        Thread C = new Thread(() -> {
            try {
                zeroEvenOdd.odd(printOdd);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        A.start();
        B.start();
        C.start();
    }
}

class ZeroEvenOdd {
    private int n;
    private Semaphore zero=new Semaphore(1);
    private Semaphore odd = new Semaphore(0);
    private Semaphore even = new Semaphore(0);



    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            zero.acquire();
            printNumber.accept(0);
            if (i%2==1)
                odd.release();
            else
                even.release();
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            even.acquire();
            printNumber.accept(i);
            zero.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            odd.acquire();
            printNumber.accept(i);
            zero.release();
        }
    }
}

