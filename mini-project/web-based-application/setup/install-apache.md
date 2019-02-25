## Apache2

[installation-instructions](https://www.digitalocean.com/community/tutorials/how-to-install-the-apache-web-server-on-ubuntu-16-04)

```shell
$ sudo apt-get install apache2 apache2-doc apache2-utils

$ hostname -I
```

copy paste the IP address to web browser.

By default, Apache Web Server is configured to run CGI programs in /var/www/cgi-bin. If you want to specify any other directory to run your CGI scripts, you can modify the following section in the apache configuration file:

```shell
$ sudo gedit gedit /etc/apache2/apache2.conf
```

```
<Directory "/var/www/cgi-bin">
   AllowOverride None
   Options ExecCGI
   Order allow,deny
   Allow from all
</Directory>
 
<Directory "/var/www/cgi-bin">
   Options All
</Directory>

AddHandler cgi-script .cgi
```