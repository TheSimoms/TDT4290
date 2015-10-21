from rest_framework import serializers

from house.models import House, Location


class HouseSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = House
        fields = ('name', 'location', 'number_of_rooms', 'color', 'inhabitants', )


class LocationSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = Location
        fields = ('name', )
