from django.contrib.auth.models import User
from django.views.generic import TemplateView

from rest_framework import viewsets

from user.serializers import UserSerializer


class UserViewSet(viewsets.ModelViewSet):
    """
    API endpoint that allows users to be viewed or edited.
    """
    queryset = User.objects.all().order_by('-date_joined')
    serializer_class = UserSerializer


class LoggedInView(TemplateView):
    template_name = 'users/logged_in.html'
