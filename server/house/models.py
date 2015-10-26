from django.db import models
from django.core.validators import MinValueValidator

from django.contrib.auth.models import User


class Location(models.Model):
    name = models.CharField(max_length=255, blank=False, null=False)

    def __unicode__(self):
        return self.name


class House(models.Model):
    COLOR_CHOICES = (
        ('red', 'Red'),
        ('orange', 'Orange'),
        ('green', 'Green'),
        ('yellow', 'Yellow'),
        ('blue', 'Blue'),
        ('indigo', 'Indigo'),
        ('violet', 'Violet'),
        ('gray', 'Gray'),
        ('black', 'Black'),
        ('pink', 'Pink'),
        ('other', 'Other'),
    )

    name = models.CharField(max_length=255, blank=False, null=False)
    location = models.ForeignKey(Location, null=False)
    number_of_rooms = models.IntegerField(null=False, validators=[MinValueValidator(1)])
    color = models.CharField(max_length=255, choices=COLOR_CHOICES, default=COLOR_CHOICES[0][0])
    inhabitants = models.ManyToManyField(User, null=False, default=[])
