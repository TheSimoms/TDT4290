#!/bin/sh

export LC_ALL="en_US.UTF-8"

pip install -r requirements.txt

python manage.py syncdb --noinput
python manage.py migrate --fake
