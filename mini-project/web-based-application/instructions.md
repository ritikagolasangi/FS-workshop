## Development guidelines for web-based application

1. Design and code the web-based HTML form to take inputs from user (in web-ui.html file). Copy this file to "/var/www/html".

2. Write a C++ CGI program to process the inputs from HTML form. Compile it using:

```shell
$g++ -o testcgi.cgi testcgi.cpp -lcgicc
```

or

```shell
$g++ -o testcgi testcgi.cpp /usr/lib/libcgicc.a
```

3. Copy the file testcgi to folder "/usr/lib/cgi-bin".

4. Point your browser to the HTML file i.e. "http://localhost/web-ui.html"