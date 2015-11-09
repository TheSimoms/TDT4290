from django.contrib.auth.models import User

from rest_framework import serializers

from house.models import House, Location


class InhabitantsField(serializers.RelatedField):
    queryset = User.objects.all()

    def to_internal_value(self, data):
        return data

    def to_representation(self, value):
        return value.pk


class HouseSerializer(serializers.ModelSerializer):
    location = serializers.PrimaryKeyRelatedField(queryset=Location.objects.all())
    color = serializers.ChoiceField(choices=House.COLOR_CHOICES, required=False)
    inhabitants = InhabitantsField(many=True, required=False)

    class Meta:
        model = House
        fields = ('name', 'location', 'number_of_rooms', 'color', 'inhabitants', )


class LocationSerializer(serializers.ModelSerializer):
    class Meta:
        model = Location
        fields = ('name', )
