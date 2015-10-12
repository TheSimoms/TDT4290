from rest_framework import routers

from testing import views as testing_views

router = routers.DefaultRouter()

router.register(r'users', testing_views.UserViewSet)
router.register(r'groups', testing_views.GroupViewSet)
