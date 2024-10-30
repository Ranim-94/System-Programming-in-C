



#pragma once

void run_thread_demo(void);


/*



 Visualizations of single-threaded vs. multi-threaded execution.


              Single-Threaded Program

          |   int x;
          |   x = 20;
          |   int y;
  Time    |   y = 50;
          |   int sum;
          |   sum = x + y;
          ↓



              Multi-Threaded Program

          |   int x;                 |  int a;
          |   x = 20;                |  a = 3;
          |   int y;                 |  int b;
  Time    |   y = 50;                |  b = 5;
          |   int sum;               |  int product;
          |   sum = x + y;           |  product = a * b;
          ↓                          ↓

          Parallel Execution
          -> same time unite



              Multi-Threaded Program

          |   int x;                 |
          |                          |  int a;
          |                          |  a = 3;
          |   x = 20;                |
          |   int y;                 |
          |                          |  int b;
  Time    |   y = 50;                |
          |                          |  b = 5;
          |                          |  int product;
          |   int sum;               |
          |   sum = x + y;           |
          |                          |  product = a * b;
          ↓                          ↓

          Concurrent But Not Parallel Execution

          CPU will switch between instruction
          both program finish at the same period of time


*/
