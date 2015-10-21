# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations
from django.conf import settings
import django.core.validators


class Migration(migrations.Migration):

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
    ]

    operations = [
        migrations.CreateModel(
            name='House',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('name', models.CharField(unique=True, max_length=255)),
                ('number_of_rooms', models.IntegerField(validators=[django.core.validators.MinValueValidator(1)])),
                ('color', models.CharField(max_length=255, choices=[(b'red', b'Red'), (b'orange', b'Orange'), (b'green', b'Green'), (b'yellow', b'Yellow'), (b'blue', b'Blue'), (b'indigo', b'Indigo'), (b'violet', b'Violet'), (b'gray', b'Gray'), (b'black', b'Black'), (b'pink', b'Pink'), (b'other', b'Other')])),
                ('inhabitants', models.ManyToManyField(to=settings.AUTH_USER_MODEL)),
            ],
        ),
        migrations.CreateModel(
            name='Location',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('name', models.CharField(unique=True, max_length=255)),
            ],
        ),
        migrations.AddField(
            model_name='house',
            name='location',
            field=models.ForeignKey(to='house.Location'),
        ),
    ]
