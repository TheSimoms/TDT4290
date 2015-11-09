## TDT4290

### Installation

#### TTCN-3 and Titan


#### Test server
First make sure that the following software packages are installed on your system:
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

### Running the test server
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
