#!/bin/sh

export LC_ALL="en_US.UTF-8"

apt-get update -y
apt-get upgrade -y
apt-get install python-dev python-virtualenv python-pip sqlite3
