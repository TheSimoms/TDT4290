from rest_framework import viewsets

from house.models import House, Location
from house.serializers import HouseSerializer, LocationSerializer


class HouseViewSet(viewsets.ModelViewSet):
    """
    API endpoint that allows users to be viewed or edited.
    """
    queryset = House.objects.all()
    serializer_class = HouseSerializer


class LocationViewSet(viewsets.ModelViewSet):
    """
    API endpoint that allows groups to be viewed or edited.
    """
    queryset = Location.objects.all()
    serializer_class = LocationSerializer
