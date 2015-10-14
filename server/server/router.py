from rest_framework import routers

from users import views as user_views

router = routers.DefaultRouter()

router.register(r'users', user_views.UserViewSet)
router.register(r'groups', user_views.GroupViewSet)
