from rest_framework import serializers

from house.models import House, Location
from user.serializers import UserSerializer


class HouseSerializer(serializers.ModelSerializer):
    location = serializers.PrimaryKeyRelatedField(queryset=Location.objects.all())
    color = serializers.ChoiceField(choices=House.COLOR_CHOICES, required=False)
    inhabitants = UserSerializer(many=True, required=False)

    class Meta:
        model = House
        fields = ('name', 'location', 'number_of_rooms', 'color', 'inhabitants', )


class LocationSerializer(serializers.ModelSerializer):
    class Meta:
        model = Location
        fields = ('name', )
