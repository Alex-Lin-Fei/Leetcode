package com.company;

import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

public class Main {

    public static void main(String[] args) {
	// write your code here
        FizzBuzz fizzBuzz = new FizzBuzz(15);
        Thread A = new Thread(()->{
            try {
                fizzBuzz.fizz(()->System.out.print("fizz"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread B = new Thread(()->{
            try {
                fizzBuzz.buzz(()->System.out.print("buzz"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread C = new Thread(()->{
            try {
                fizzBuzz.fizzbuzz(()->System.out.print("fizzbuzz"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread D = new Thread(()->{
            try {
                fizzBuzz.number(new IntConsumer() {
                    @Override
                    public void accept(int value) {
                        System.out.print(value);
                    }
                });
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        A.start();
        B.start();
        C.start();
        D.start();

    }
}

class FizzBuzz {
    private Semaphore semaphore = new Semaphore(1);
    private int n;
    private int curNum;

    public FizzBuzz(int n) {
        this.n = n;
        this.curNum = 1;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        while (this.curNum <= n) {
            try {
                semaphore.acquire();
                if (this.curNum>n)
                    return;
                if (this.curNum % 3 == 0 && this.curNum % 5 != 0) {
                    this.curNum++;
                    printFizz.run();
                }
            } finally {
                semaphore.release();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while (this.curNum<=n) {
            try {
                semaphore.acquire();
                if (this.curNum>n)
                    return;
                if (this.curNum % 3 != 0 && this.curNum % 5 == 0) {
                    this.curNum++;
                    printBuzz.run();
                }
            } finally {
                semaphore.release();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (this.curNum<=n) {
            try {
                semaphore.acquire();
                if (this.curNum>n)
                    return;
                if (this.curNum % 3 == 0 && this.curNum % 5 == 0) {
                    this.curNum++;
                    printFizzBuzz.run();
                }
            } finally {
                semaphore.release();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        while (this.curNum<=n) {
            try {
                semaphore.acquire();
                if (this.curNum>n)
                    return;
                if (this.curNum % 3 != 0 && this.curNum % 5 != 0) {
                    printNumber.accept(this.curNum);
                    this.curNum++;
                }
            } finally {
                semaphore.release();
            }
        }
    }
}
