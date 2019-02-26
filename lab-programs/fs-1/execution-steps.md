

# Compilation Steps

```shell

$g++ reader.cpp -o reader

$g++ writer.cpp -o writer

$g++ fs1.cpp

```

## Run-1

```shell

$./a.out

1. Console I/O

2. File I/O

Enter your choice: 1

Enter the number of students: 2

Enter 1 student name:

tom

Enter 2 student name:

(2) Read &quot;tom&quot; from FIFO file

(3) Reversed Name is: mot

(1) Wrote &quot;tom&quot; to FIFO file

harry

(2) Read &quot;harry&quot; from FIFO file

(3) Reversed Name is: yrrah

(1) Wrote &quot;harry&quot; to FIFO file

```

## Run-2

```shell

$cat \&gt; f.txt

fan

pox [enter]

ctrl + z

$./a.out

1. Console I/O

2. File I/O

Enter your choice: 2

Enter the file name, from which you want to read the names:

f.txt

Enter the file name, from which you want to write the reversed names:

o.txt

(1) Wrote &quot;pox&quot; to FIFO file

(2) Read &quot;fan&quot; from FIFO file

(2) Read &quot;pox&quot; from FIFO file

(1) Wrote &quot;fan&quot; to FIFO file

(3) Wrote &quot;naf&quot; to o.txt file

(3) Wrote &quot;xop&quot; to o.txt file



$cat f.txt

fan

pox

$cat o.txt

naf

xop

```


