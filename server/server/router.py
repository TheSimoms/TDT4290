from rest_framework import routers

from user import views as user_views
from house import views as house_views

router = routers.DefaultRouter()

router.register(r'users', user_views.UserViewSet)

router.register(r'houses', house_views.HouseViewSet)
router.register(r'locations', house_views.LocationViewSet)
