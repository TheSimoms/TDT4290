from django.conf.urls import include, url
from django.contrib import admin

from router import router

from users.views import LoggedInView

urlpatterns = [
    url(r'^admin/', include(admin.site.urls)),
    url(r'^auth/', include('rest_framework.urls', namespace='rest_framework')),
    url(r'^api/', include(router.urls)),
    url(r'^success/', LoggedInView.as_view()),
]
