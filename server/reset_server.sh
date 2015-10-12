#!/bin/sh

# To avoid character encoding issues
export LC_ALL="en_US.UTF-8"

# Install Python requirements
pip install -r requirements.txt

# Removes old database
rm db.sqlite3

# Sets up new database and loads test data
python manage.py syncdb --noinput
python manage.py migrate --fake
python manage.py loaddata server/fixtures/fixtures.json
