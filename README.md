## TDT4290

TTCN-3 test suite for testing the HTTP protocol.

The system spawns a HTTP server, which the test suite then tests.

### Installation

#### TTCN-3 and Titan
In the development of this project, Eclipse's IDE for C/C++ has been used. The team has also used Titan, a plug-in for Eclipse. Eclipse and Titan are not required in order to run the system, but they are recommended for developing.

The Titan plug-in and the binaries for TTCN-3 can be found at https://projects.eclipse.org/projects/tools.titan/downloads. Instrictions on how to install the TTCN-3 binaries can be found inside the `doc` folder of the compressed folder containing the binaries.

#### Test web server
The following software packages are used to install and run the test server:
  * Python 2.7
  * Virtualenv for Python 2.7
  * Python-pip for Python 2.7
  * SQLite

For Ubuntu 14.04, issue the following commands in order to install the requirements:
```bash
cd server
sudo ./setup.sh
```

After installing the packages, issue the following commands in order to set up a virtual Python environment:
```bash
virtualenv --distribute TDT4290
. TDT4290/bin/activate
./reset_server.sh
```

### Running

#### Test web server
Make sure you are located in the server folder of the project.

Activate the virtual environment:
```bash
. TDT4290/bin/activate
```

If any changes has been made, reset the server, and update the dependencies:
```bash
./reset_server.sh
```

Then, start the test server:
```bash
./manage.py runserver
```

The server can now be accessed at `http://localhost:8000/` in your web browser.
An admin user with username 'admin' and password 'password' has been added to the database.

#### TTCN-3 suite
A simple shell script has been made for building the suite. It can be found at `ttcn3/build.sh`. The script simply uses the built-in TTCN-3 function for generating a Makefile before making the project.

A simple script has also been made for running the suite. This script uses the configuration file `ttcn3/config.cfg` for choosing what tests to run.

It is important to run the scripts from the `ttcn3/` folder, as they refer to relative paths.
